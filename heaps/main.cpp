#include <iostream>
#include <vector>

using namespace std;

class Heap
{
private:
    vector<int> heap;

    // Helper fns
    int parent(int index)
    {
        return (index - 1) / 2;
    }

    void swap(int from, int to)
    {
        int temp = heap[from];
        heap[from] = heap[to];
        heap[to] = temp;
    }

    int leftChild(int index)
    {
        return 2 * index + 1;
    }

    int rightChild(int index)
    {
        return 2 * index + 2;
    }

public:
    void insert(int value)
    {
        heap.push_back(value);
        int currentIdx = heap.size() - 1;

        while (currentIdx > 0 && heap[currentIdx] > heap[parent(currentIdx)])
        {
            swap(currentIdx, parent(currentIdx));
            currentIdx = parent(currentIdx);
        }
    }

    int remove()
    {
        if (heap.empty())
        {
            return INT32_MIN;
        }

        int maxValue = heap.front();

        if (heap.size() == 1)
        {
            heap.pop_back();
        }
        else
        {
            heap[0] = heap.back();
            heap.pop_back();

            sinkDown(0);
        }

        return maxValue;
    }

    void sinkDown(int index)
    {
        int maxIndex = index;
        while (true)
        {
            int leftIdx = leftChild(index);
            int rightIdx = rightChild(index);

            if (leftIdx < heap.size() && heap[leftIdx] > heap[maxIndex])
            {
                maxIndex = leftIdx;
            }

            if (rightIdx < heap.size() && heap[rightIdx] > heap[maxIndex])
            {
                maxIndex = rightIdx;
            }

            if(maxIndex != index) {
                swap(index, maxIndex);
                index = maxIndex;
            } else {
                break;
            }
        }
    }
};

int main()
{
    Heap *heap = new Heap();

    heap->insert(100);
    heap->insert(99);
    heap->insert(75);
    heap->insert(58);
    heap->insert(72);
    heap->insert(61);
    heap->remove();
    heap->remove();
    return 0;
}