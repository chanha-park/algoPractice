{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

main :: IO ()
main = print . sum . takeWhile (< 4000000) . filter even $ fibo

fibo :: [Integer]
fibo = fibo' 1 2

fibo' :: Num t => t -> t -> [t]
fibo' x y = x : fibo' y (x + y)
