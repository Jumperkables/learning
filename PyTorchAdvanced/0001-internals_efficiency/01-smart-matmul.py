import torch

# Make a well distributed 2x2 Matrix with given sparsity
sparsity = 0.8
well_dist = torch.threshold(torch.rand(6400,6400), sparsity, 0)
well_dist_csr = well_dist.to_sparse(layout=torch.sparse_csr)   # Compressed row format
well_dist_csc = well_dist.to_sparse(layout=torch.sparse_csc)   # Compressed column format
well_dist_coo = well_dist.to_sparse(layout=torch.sparse_coo)   # Co-ordinate rep
breakpoint()
well_dist_bsr = well_dist.to_sparse(layout=torch.sparse_bsr)   # Block compressed sparse row format