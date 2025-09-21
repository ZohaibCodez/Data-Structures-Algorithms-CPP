#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class NDArray
{
private:
    T *data;
    int *dimensions;
    int *strides;
    int ndim;
    int total_size;

    // utility functions
    void calculate_strides()
    {
        strides = new int[ndim];
        strides[ndim - 1] = 1;
        for (int i = ndim - 2; i >= 0; i--)
        {
            strides[i] = strides[i + 1] * dimensions[i + 1];
        }
    }

    void calculate_total_size()
    {
        total_size = 1;
        for (int i = 0; i < ndim; i++)
        {
            total_size *= dimensions[i];
        }
    }

    int flat_index(int *indices) const
    {
        int idx = 0;
        for (int i = 0; i < ndim; i++)
        {
            if (indices[i] < 0 || indices[i] >= dimensions[i])
            {
                throw out_of_range("Index out of range:(");
            }
            idx += indices[i] * strides[i];
        }
        return idx;
    }

public:
    // Constructor
    NDArray(int *dims, int num_dims) : ndim(num_dims)
    {
        if (ndim <= 0)
        {
            throw invalid_argument("Number of dimensions must be positive:(");
        }

        dimensions = new int[ndim];
        for (int i = 0; i < ndim; i++)
        {
            if (dims[i] <= 0)
            {
                throw invalid_argument("All dimensions must be positive:(");
            }
            dimensions[i] = dims[i];
        }
        this->calculate_total_size();
        calculate_strides();
        data = new T[total_size]();
    }

    // Copy Constructor
    NDArray(const NDArray &other) : ndim(other.ndim), total_size(other.total_size)
    {
        dimensions = new int[ndim];
        strides = new int[ndim];
        data = new T[total_size];

        for (int i = 0; i < ndim; i++)
        {
            dimensions[i] = other.dimensions[i];
            strides[i] = other.strides[i];
        }

        for (int i = 0; i < total_size; i++)
        {
            data[i] = other.data[i];
        }
    }

    // Assignment Operator
    NDArray &operator=(const NDArray &other)
    {
        if (this != &other)
        {
            delete[] data;
            delete[] dimensions;
            delete[] strides;

            ndim = other.ndim;
            total_size = other.total_size;

            dimensions = new int[ndim];
            strides = new int[ndim];
            data = new T[total_size];

            for (int i = 0; i < ndim; i++)
            {
                dimensions[i] = other.dimensions[i];
                strides[i] = other.strides[i];
            }

            for (int i = 0; i < total_size; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~NDArray()
    {
        delete[] data;
        delete[] dimensions;
        delete[] strides;
    }

    // Access opertor --> at[]
    T &at(int *indices)
    {
        return data[flat_index(indices)];
    }

    const T &at(int *indices) const
    {
        return data[flat_index(indices)];
    }

    // get element same as access operator
    T get(int *indices) const
    {
        return data[flat_index(indices)];
    }

    // fill array with some specific value
    void fill(const T &value)
    {
        for (int i = 0; i < total_size; i++)
        {
            data[i] = value;
        }
    }

    // Getters
    int get_ndim() const { return ndim; }
    int get_size() const { return total_size; }

    int get_dimension(int dim) const
    {
        if (dim < 0 || dim >= ndim)
        {
            throw out_of_range("Axis out of bounds:(");
        }
        return dimensions[dim];
    }
};

int main()
{
    // int dims2d[] = {3, 3};
    // NDArray<double> matrix(dims2d, 2);
    // matrix.fill(1.5);

    // cout << "\nCase 1: Filled 2D matrix with 1.5\n";
    // for (int i = 0; i < matrix.get_dimension(0); i++)
    // {
    //     for (int j = 0; j < matrix.get_dimension(1); j++)
    //     {
    //         int idx[2] = {i, j};
    //         cout << matrix.at(idx) << " ";
    //     }
    //     cout << endl;
    // }
    int dims2d[] = {3, 3};      // 3x3 matrix
    NDArray<double> matrix(dims2d, 2);

    matrix.fill(1.5);           // fill with 1.5

    cout << "Filled 2D matrix:\n";
    for (int i = 0; i < matrix.get_dimension(0); i++) {
        for (int j = 0; j < matrix.get_dimension(1); j++) {
            int idx[2] = {i, j};   // index = (i,j)
            cout << matrix.at(idx) << " ";
        }
        cout << endl;
    }

}