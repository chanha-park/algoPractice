{-# OPTIONS_GHC -Wall -Wextra -Wall #-}

main :: IO ()
main = print . solve $ 100

solve :: Int -> Int
solve n = sumThenSquare n - squareThenSum n

sumThenSquare :: Int -> Int
sumThenSquare n = div (n * (n + 1)) 2 ^ (2 :: Int)

squareThenSum :: Int -> Int
squareThenSum n = div (n * (n + 1) * (2 * n + 1)) 6
