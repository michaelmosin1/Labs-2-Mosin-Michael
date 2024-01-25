#ifndef rectangles
#define rectangles

namespace mm{
    class rectangle{
        private:
            float _height;
            float _width;
            bool _is_empty;
        public:
            rectangle(float height, float width);
            rectangle();
            ~rectangle();
            bool is_empty();
            void set_size(float height, float width);
            float area();
            float perimeter();
            float diagonal();
            void print_out();
    };
}
#endif