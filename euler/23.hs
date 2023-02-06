{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

import Data.Set qualified as Set

num :: Int
num = 28123

main :: IO ()
main = print . sum . filter (not . isSumOfTwoAbundant) $ [1 .. num]

isSumOfTwoAbundant :: Int -> Bool
isSumOfTwoAbundant n
    | n < 24 = False
    | otherwise =
        any ((`Set.member` setAbundant) . (n -))
            . filter (`Set.member` setAbundant)
            $ [1 .. (n - 1)]

setAbundant :: Set.Set Int
setAbundant = Set.fromList . filter isAbundant $ [0 .. num]

isAbundant :: Int -> Bool
isAbundant 0 = False
isAbundant 1 = False
isAbundant n = n < sumDivisor n

sumDivisor :: Int -> Int
sumDivisor n = foldr fn 1 (factorize n) - n
  where
    fn (p, x) c = div ((p ^ (x + 1)) - 1) (p - 1) * c

factorize :: Int -> [(Int, Int)]
factorize n = factor' n 2 []
  where
    factor' :: Int -> Int -> [(Int, Int)] -> [(Int, Int)]
    factor' 1 _ xs = xs
    factor' m p xs
        | p * p > m = (m, 1) : xs
        | mod m p == 0 = factor' m' (p + 1) ((p, x) : xs)
        | otherwise = factor' m (p + 1) xs
      where
        (m', x) = countOrder m p 0
        countOrder :: Int -> Int -> Int -> (Int, Int)
        countOrder a b acc
            | mod a b == 0 = countOrder (div a b) b (acc + 1)
            | otherwise = (a, acc)
