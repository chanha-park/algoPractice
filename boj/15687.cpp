
class Rectangle {
 private:
  int width;
  int height;

 protected:
 public:
  Rectangle(int width, int height) : width(width), height(height) {
  }

  int get_width(void) const {
    return (width);
  }

  int get_height(void) const {
    return (height);
  }

  void set_width(int w) {
    if (w > 0 && w <= 1000)
      this->width = w;
  }

  void set_height(int h) {
    if (h > 0 && h <= 2000)
      this->height = h;
  }

  int area(void) const {
    return (width * height);
  }

  int perimeter(void) const {
    return ((width + height) << 1);
  }

  bool is_square(void) const {
    return (width == height);
  }
};
