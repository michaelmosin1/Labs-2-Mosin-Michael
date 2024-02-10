#ifndef int_matrix
#define int_matrix


namespace mm{
    class matrix{
        private:
            bool is_matrix_empty;
            int N_size;
            int M_size;
            int** data;
        public:
            matrix();
            matrix(int N, int M);
            ~matrix();
            void fill_with_data();
            void print();
            matrix(const matrix& other);
            mm::matrix& operator=(const matrix& other);
    };
}


#endif