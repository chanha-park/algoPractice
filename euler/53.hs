{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

main :: IO ()
main =
    print
        . sum
        . map (length . filter (> 1000000) . combList)
        $ [0 .. 100]

dp :: [[Integer]]
dp = map combList [0 ..]

combList :: Int -> [Integer]
combList n = map (comb n) [0 .. n]

comb :: Int -> Int -> Integer
comb _ 0 = 1
comb n 1 = toInteger n
comb n r
    | r > n - r = (dp !! n) !! (n - r)
    | otherwise = ((dp !! (n - 1)) !! r) + ((dp !! (n - 1)) !! (r - 1))
