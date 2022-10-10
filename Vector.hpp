
#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <iostream>
#include <stdarg.h>
#include <cassert>

template <typename elem_type, std::size_t size>
class KernalVector {
    private:
        size_t size_;
        elem_type* vector_;
    public:
        KernalVector():
            size_(size),
            vector_(new elem_type[size_])
            {}

        KernalVector(const KernalVector& kernal_vector):
            size_(kernal_vector.get_size()),
            vector_(new elem_type[size_])
            {
                for (size_t i = 0; i < size_; i++) {
                    vector_[i] = kernal_vector.get_vector_elem(i);
            }
        }
        KernalVector& operator = (const KernalVector& kernal_vector) {
            delete [] vector_;

            size_ = kernal_vector.get_size();
            vector_ = new elem_type[size_];
            for (size_t i = 0; i < size_; i++) {
                vector_[i] = kernal_vector.get_vector_elem(i);
            }

            return *this;
        }
        ~KernalVector() {
            delete [] vector_;
        }

        size_t get_size() const { return size_; }

        elem_type& get_vector_elem(const size_t i) const { return vector_[i]; }
        void set_vector_elem(const size_t i, const elem_type elem) { vector_[i] = elem; }
};

template <typename elem_type, std::size_t size>
class Vector {
    private:
        KernalVector<elem_type, size> kernal_vector_;
    public:
        KernalVector<elem_type, size> get_kernal_vector() const { return kernal_vector_; }

        Vector():
            kernal_vector_()
            {}

        Vector(const Vector& vector):
            kernal_vector_(vector.get_kernal_vector())
            {}
        Vector& operator = (const Vector& vector) {
            kernal_vector_ = vector.get_kernal_vector();

            return *this;
        }
        ~Vector() {}

        double& operator [] (const size_t i) {
            if (i < kernal_vector_.get_size()) {
                return kernal_vector_.get_vector_elem(i);
            } else {
                std::cout << "Invalid index\n";
                assert(0);
            }
        }

        const double& operator [] (const size_t i) const {
            if (i < kernal_vector_.get_size()) {
                return kernal_vector_.get_vector_elem(i);
            } else {
                std::cout << "Invalid index\n";
                assert(0);
            }
        }

        void print_vector() const {
            for (size_t i = 0; i < kernal_vector_.get_size(); i++) {
                std::cout << kernal_vector_.get_vector_elem(i) << "\n";
            }
        }
};

#endif // VECTOR_HPP_
