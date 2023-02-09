{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

import Data.List

l :: [Integer]
l = [2 .. 100]

main :: IO ()
main =
    print
        . length
        . map head
        . myGroup
        . mySortBy compare
        $ [a ^ b | a <- l, b <- l]

myGroup :: Eq a => [a] -> [[a]]
myGroup [] = []
myGroup (x : xs) = ys : myGroup zs
  where
    (ys, zs) = splitWhile (== x) (x : xs)

splitWhile :: (a -> Bool) -> [a] -> ([a], [a])
splitWhile _ [] = ([], [])
splitWhile fn (x : xs)
    | fn x = (x : ys, zs)
    | otherwise = ([], x : xs)
  where
    (ys, zs) = splitWhile fn xs

mySortBy :: Ord a => (a -> a -> Ordering) -> [a] -> [a]
mySortBy = sortBy
