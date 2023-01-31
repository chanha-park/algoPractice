{-# OPTIONS_GHC -Wall -Wextra -Wall #-}

main :: IO ()
main = print $ comb 40 20

dp :: [[Integer]]
dp = [] : map combList [1 .. 40]

combList :: Int -> [Integer]
combList n = map (comb n) [0 .. n]

comb :: Int -> Int -> Integer
comb _ 0 = 1
comb n r
    | r > n - r = (dp !! n) !! (n - r)
    | otherwise = ((dp !! (n - 1)) !! r) + ((dp !! (n - 1)) !! (r - 1))
