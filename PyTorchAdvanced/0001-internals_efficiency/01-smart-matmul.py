import torch

# Make a well distributed 2x2 Matrix with given sparsity
sparsity = 0.8
well_dist = torch.threshold(torch.rand(6400,6400), sparsity, 0)
well_dist_coo = A.to_sparse(torch.sparse_coo)   # Co-ordinate rep
well_dist_csr = A.to_sparse(torch.sparse_csr)   # Compressed row format
well_dist_bsr = A.to_sparse(torch.sparse_bsr)   # Block compressed sparse row format
