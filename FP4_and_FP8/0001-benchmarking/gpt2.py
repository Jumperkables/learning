# standard imports
import time

# 3rd party imports
import torch
from transformers import AutoModelForCausalLM, AutoTokenizer
import transformer_engine.pytorch as te
from transformer_engine.common.recipe import Format, DelayedScaling


# Torch device sanity checks
print(torch.cuda.device_count())
print("cuda:0 ", torch.cuda.get_device_name(0))
print("cuda:1 ", torch.cuda.get_device_name(1))


# Models
model_3090 = AutoModelForCausalLM.from_pretrained("gpt2").to("cuda:0")
model_5060ti = AutoModelForCausalLM.from_pretrained("gpt2").to("cuda:1")


# Inputs
tokenizer = AutoTokenizer.from_pretrained("gpt2")
inputs = tokenizer("I will not let this republic that has stood for 1000 years be split in 2", return_tensors="pt")
inputs_3090 = {k: v.to("cuda:0") for k, v in inputs.items()}
inputs_5060ti = {k: v.to("cuda:1") for k, v in inputs.items()}


# Benchmarking 
## On 3090
start_3090 = time.time()
with torch.no_grad():
    output_3090 = model_3090(**inputs_3090)
end_3090 = time.time()

## On 5060 Ti
start_5060ti = time.time()
with torch.no_grad():
    output_5060ti = model_5060ti(**inputs_5060ti)
end_5060ti = time.time()

print(f"3090 Inference Time: {end_3090 - start_3090:.4f} seconds")
print(f"5060ti Inference Time: {end_5060ti - start_5060ti:.4f} seconds")