import time
import torch

M, N, K = 2000, 2000, 2000
BLOCK_SIZE = 10
SPARSITY = 0.99
BAND_WIDTH = 5
NUM_BLOCKS = 10
NUM_NNZ_ROWS = 10
NUM_NNZ_COLS = 10

BANNED_NAME_PAIRS = [
    {'csr  ', 'coo  '},
    {'csc  ', 'coo  '},
]

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')


def create_well_dist(sparsity):
    well_dist_dense = torch.threshold(torch.rand(M, N), sparsity, 0).to(device)
    well_dist_coo = well_dist_dense.to_sparse(layout=torch.sparse_coo).to(device)
    well_dist_csr = well_dist_dense.to_sparse(layout=torch.sparse_csr).to(device)
    well_dist_csc = well_dist_dense.to_sparse(layout=torch.sparse_csc).to(device)
    #well_dist_bsr = well_dist_dense.to_sparse_bsr(blocksize=BLOCK_SIZE).to(device)
    return_dict = {
        'dense': well_dist_dense,
        'coo  ': well_dist_coo,
        'csr  ': well_dist_csr,
        'csc  ': well_dist_csc,
        #'bsr  ': well_dist_bsr
    }
    return return_dict


def create_diag_banded(band_width):
    diag_banded_dense = torch.rand(M, N).to(device)
    for i in range(M):
        for j in range(N):
            if abs(i-j) > band_width:
                diag_banded_dense[i,j] = 0
    diag_banded_coo = diag_banded_dense.to_sparse(layout=torch.sparse_coo).to(device)
    diag_banded_csr = diag_banded_dense.to_sparse(layout=torch.sparse_csr).to(device)
    diag_banded_csc = diag_banded_dense.to_sparse(layout=torch.sparse_csc).to(device)
    #diag_banded_bsr = diag_banded_dense.to_sparse_bsr(blocksize=BLOCK_SIZE).to(device)
    return_dict = {
        'dense': diag_banded_dense,
        'coo  ': diag_banded_coo,
        'csr  ': diag_banded_csr,
        'csc  ': diag_banded_csc,
        #'bsr  ': diag_banded_bsr
    }
    return return_dict


def create_block_sparse(block_size, num_blocks):
    indices = []
    values = []
    for _ in range(num_blocks):
        i_start = torch.randint(0, M - block_size, (1,)).item()
        j_start = torch.randint(0, N - block_size, (1,)).item()
        for i in range(i_start, i_start + block_size):
            for j in range(j_start, j_start + block_size):
                indices.append([i, j])
                values.append(torch.randn(1).item())
    indices = torch.tensor(indices).T
    values = torch.tensor(values)
    block_sparse_dense = torch.sparse_coo_tensor(indices, values, (M, N)).coalesce().to_dense().to(device)
    block_sparse_coo = block_sparse_dense.to_sparse(layout=torch.sparse_coo).to(device)
    block_sparse_csr = block_sparse_dense.to_sparse(layout=torch.sparse_csr).to(device)
    block_sparse_csc = block_sparse_dense.to_sparse(layout=torch.sparse_csc).to(device)
    #block_sparse_bsr = block_sparse_dense.to_sparse_bsr(blocksize=block_size).to(device)
    return_dict = {
        'dense': block_sparse_dense,
        'coo  ': block_sparse_coo,
        'csr  ': block_sparse_csr,
        'csc  ': block_sparse_csc,
        #'bsr  ': block_sparse_bsr
    }
    return return_dict


def create_row_sparse(num_nnz_rows):
    row_sparse_dense = torch.rand(M, N).to(device)
    row_indices = torch.randint(0, M, (num_nnz_rows,))
    row_sparse_dense[row_indices] = 0
    row_sparse_coo = row_sparse_dense.to_sparse(layout=torch.sparse_coo).to(device)
    row_sparse_csr = row_sparse_dense.to_sparse(layout=torch.sparse_csr).to(device)
    row_sparse_csc = row_sparse_dense.to_sparse(layout=torch.sparse_csc).to(device)
    #row_sparse_bsr = row_sparse_dense.to_sparse_bsr(blocksize=BLOCK_SIZE).to(device)
    return_dict = {
        'dense': row_sparse_dense,
        'coo  ': row_sparse_coo,
        'csr  ': row_sparse_csr,
        'csc  ': row_sparse_csc,
        #'bsr  ': row_sparse_bsr
    }
    return return_dict


def create_col_sparse(num_nnz_cols):
    col_sparse_dense = torch.rand(M, N).to(device)
    col_indices = torch.randint(0, N, (num_nnz_cols,))
    col_sparse_dense[:, col_indices] = 0
    col_sparse_coo = col_sparse_dense.to_sparse(layout=torch.sparse_coo).to(device)
    col_sparse_csr = col_sparse_dense.to_sparse(layout=torch.sparse_csr).to(device)
    col_sparse_csc = col_sparse_dense.to_sparse(layout=torch.sparse_csc).to(device)
    #col_sparse_bsr = col_sparse_dense.to_sparse_bsr(blocksize=BLOCK_SIZE).to(device)
    return_dict = {
        'dense': col_sparse_dense,
        'coo  ': col_sparse_coo,
        'csr  ': col_sparse_csr,
        'csc  ': col_sparse_csc,
        #'bsr  ': col_sparse_bsr
    }
    return return_dict


if __name__ == "__main__":
    well_dist = create_well_dist(SPARSITY)
    diag_banded = create_diag_banded(BAND_WIDTH)
    block_sparse = create_block_sparse(BLOCK_SIZE, NUM_BLOCKS)
    row_sparse = create_row_sparse(NUM_NNZ_ROWS)
    col_sparse = create_col_sparse(NUM_NNZ_COLS)
    all_dicts = {
        "Well Dist   ": well_dist,
        "Diag Banded ": diag_banded,
        "Block Sparse": block_sparse,
        "Row Sparse  ": row_sparse,
        "Col Sparse  ": col_sparse
    }
    
    for key1, val1 in all_dicts.items():
        for key2, val2 in all_dicts.items():
            for name1, tensor1 in val1.items():
                for name2, tensor2 in val2.items():
                    if not (name1 == 'dense' and name2 == 'dense'):
                        continue
                    if set([name1, name2]) not in BANNED_NAME_PAIRS:
                        start = time.time()
                        tensor1 @ tensor2
                        end = time.time()
                        print(f"{key1} {name1} x {key2} {name2}: {end-start:.7f} s")
                #print('\n')