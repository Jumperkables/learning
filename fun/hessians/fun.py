# standard imports

# 3rd party imports
import torch
from torch import nn
import transformer_engine.pytorch as te

# local imports


"""
ChatGPT helped me learn how to benchmark between FP8 
"""

class TinyNetTE(nn.Module):
    def __init__(self, use_fp8=False):
        super().__init__()
        self.linear = te.Linear(
            in_features=2,
            out_features=3,
            bias=True,
        )

    def forward(self, x):
        return self.linear(x)


if __name__ == "__main__":
    # Device
    # 3090 on GPU0      (no native FP8 but fast GPU)
    # 5060ti on GPU1    (native FP* but slower GPU)
    blackwell = False
    if blackwell:
        device = 1
    else:
        device = 0

    use_fp8 = False
    model = TinyNetTE(use_fp8=use_fp8).cuda()  # must be on GPU
    x = torch.tensor([[1.5, 2.5]], device=device, requires_grad=True)
    target = torch.tensor([[3.0, 2.0, 1.0]], device=device)
    output = model(x)
    def mse(output, target):
        loss = (output - target).pow(2).sum()
        return loss

    loss = mse(output, target)
    grad = torch.autograd.grad(loss, model.parameters(), create_graph=True)
    breakpoint()
    #(weight_grad, bias_grad) = grad

    #hessian = torch.autograd.grad(weight_grad, model.parameters())
    #(weight_hessian, bias_hessian) = hessian

    full_hessian = torch.autograd.functional.hessian(mse, x)

    print("Gradient:", weight_grad.item())
    print("Hessian:", weight_hessian.item())