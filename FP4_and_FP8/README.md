# Floating Point 4 and 8 Experiments
- FP4 and FP8 have a stronger future in ML
- I have a 3090 and a 5060ti, perfect for benchmarking the differences between FP4 and 8 on chip and not

## 0001-benchmarking
Benchmarking my 3090 performance against my 5060ti performance

#### Hardware setup and performance notes
| Type | Model | Notes |
| -------- | -------- | -------- |
 CPU | AMD Ryzen 9 7900X3D 12-Core | Haters on reddit kept the price low for me, thanks guys |
| Motherboard | MSI MPG X670E CARBON WIFI Motherboard, ATX | Bifrucates my 2 GPUs to x8 and x8. They should be the same speed. |
| RAM | CORSAIR VENGEANCE DDR5 64GB (2x32GB) DDR5 6000MHz CL40 AMD EXPO Intel XMP | NaN |
| GPU1 | 3090: MSi GeForce RTX Gaming X Trio 24GB GDDR6X | Got it 2nd hand on CeX |
| GPU2 | 5060ti 16GB: Gigabyte NVIDIA GeForce RTX 5060 Ti WINDFORCE 16GB GDDR7 | Got it for MSRP release date. Nice |

##### GPUs
- My 3090 is in the PCI_E1 slot (PCIe 5.0x16)
- 5060ti in the PCI_E2 slot (PCIe 5.0x8)
- HOWEVER: According to my understanding the [motherboard manual](https://download-2.msi.com/archive/mnu_exe/mb/MPGX670ECARBONWIFI.pdf) page 33/31, this set up has a brifuraction x8 x8 split. Both GPUs should run at the same relative speed.
    * Interestingly my 5060ti has an x8 PCI connector. So nothing is wasted on it in the bifrucation as i understand

## Mistal-7B