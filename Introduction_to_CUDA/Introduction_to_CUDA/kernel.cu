
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

const int array_size = 32*32;
const int allocation_size = array_size * sizeof(int);

void* cpu_allocation;
void* gpu_allocation;

int a;

void cpu_set_array() {
	int* cpu_int32 = (int*)cpu_allocation;

	for (int i = 0; i < array_size; i++) {
		cpu_int32[i] = i;
	}
}
void cpu_alloc(){
	cpu_allocation = (void*)malloc(allocation_size); // malloc geri dönüş değeri zaten void * tipinde olacak,sadece paşa keyfim yazmak istedi
}
void cpu_free() {
	free(cpu_allocation);
}
void gpu_alloc() {
	cudaError_t result = cudaMalloc(&gpu_allocation,allocation_size); // Imagine like system call.
	assert(result == 0);
}
void gpu_free() {
	cudaError_t result = cudaFree(gpu_allocation);
	assert(result == 0);
}
void cpu_mem_to_gpu_mem() {
	cudaError_t result = cudaMemcpy(gpu_allocation,cpu_allocation,allocation_size,cudaMemcpyHostToDevice);
	assert(result == 0);
}
void gpu_mem_to_cpu_mem() {
	cudaError_t result = cudaMemcpy(cpu_allocation, gpu_allocation, allocation_size, cudaMemcpyDeviceToHost);
	assert(result == 0);
}

__global__ void gpu_add(int* gpu_numbers) {
	int thread_index_in_block = threadIdx.x; // bölüt içerisinde izleğin indisi
	int block_index_in_grid = blockIdx.x;	// ızgara içerisinde bölütün indisi
	//int thread_count_in_one_block = blockDim.x;		// bölütün içerisinde kaç tane izlek var
	//int number_of_blocks_in_grid = gridDim.x;	// ızgara kaç tane bölüt içeriyor

	int id = blockDim.x * blockIdx.x + threadIdx.x;// her bir izleğe eşsiz bir indis oluşturma

	if (thread_index_in_block == 29 && block_index_in_grid == 0  ) {
		printf("");
	}
	gpu_numbers[id] *= 3;

}

void print_number() {

	int* numbers = (int*)cpu_allocation;
	for (int i = 0; i < array_size; i++) {
		printf("%d \t %d\n", i, numbers[i]);
	}
}
int main()
{
	cpu_alloc();
	gpu_alloc(); // en son hangisini tahsis ettiysen ilk onu boşalt

	cpu_set_array();

	cpu_mem_to_gpu_mem();

	int block_dimension = 64; //bu sayı bir bölüt içerisinde çalışacak izlek sayısını temsil etmektedir.bunu kendim ayarlıyorum şu an için.
	int grid_dimension = array_size / block_dimension; //Özdevimli olarak bu diziyi eş zamanlı atayacak ızgara bölüt sayısını ayarlıyorum.



	gpu_add <<<grid_dimension,block_dimension >>> ((int*)(gpu_allocation)); // bir bölüt(block) en fazla 1024 izlek içerebilir,	number of blocks , number of threads per block 
	cudaError_t result  = cudaDeviceSynchronize();
	assert(result == cudaSuccess);

	gpu_mem_to_cpu_mem();

	print_number();


	gpu_free();
	cpu_free();
}

//CUDA'da bellek tahsisi maliyetli bir işlem olduğu için olduğunca algoritma düzeyinde bellek sorunları çözülmelidir.
