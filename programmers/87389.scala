object Solution {
    def solution(n: Int): Int = {
        return impl(n - 1, 2);
    }

    val impl: (Int, Int) => Int = (n, x) =>
      if (n % x == 0) x
      else if (x > n / x) n
      else impl(n, x + 1)
}
