import torch

# Define two sparse tensors
indices1 = torch.tensor([[0, 1], [0, 2]])  # Indices for tensor 1
values1 = torch.tensor([3, 4])  # Values for tensor 1

indices2 = torch.tensor([[0, 1], [0, 2]])  # Same indices for tensor 2
values2 = torch.tensor([1, 2])  # Values for tensor 2

# Create sparse tensors
sparse_tensor1 = torch.sparse_coo_tensor(indices1, values1, (2, 3))
sparse_tensor2 = torch.sparse_coo_tensor(indices2, values2, (2, 3))
breakpoint()
# Add the sparse tensors
result = sparse_tensor1 + sparse_tensor2

# Multiply the result without coalescing
result_mul = result * torch.tensor([2, 2, 2])  # Multiplying with a dense tensor
print("Result (without coalescing) of multiplication:")
print(result_mul)

# Coalesce before using the result in further operations
coalesced_result = result.coalesce()

# Now multiply the coalesced result
coalesced_result_mul = coalesced_result * torch.tensor([2, 2, 2])
print("\nResult (after coalescing) of multiplication:")
print(coalesced_result_mul)