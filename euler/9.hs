{-# OPTIONS_GHC -Wall -Wextra -Wall #-}

main :: IO ()
main =
    print . head $
        [ a m n * b m n * c m n
        | (n :: Int) <- [1 .. 500]
        , m <- [n + 1 .. 500]
        , m * (m + n) == 500
        ]

a :: Num a => a -> a -> a
a m n = m * m - n * n

b :: Num a => a -> a -> a
b m n = 2 * m * n

c :: Num a => a -> a -> a
c m n = m * m + n * n
