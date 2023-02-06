{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

import Data.List

main :: IO ()
main = print . nthPermutation 999999 . sort $ "0123456789"

nthPermutation :: Int -> [a] -> [a]
nthPermutation _ [] = []
nthPermutation n xs = (xs !! p) : nthPermutation n' (ys ++ tail zs)
  where
    f = factorial 1 (length xs - 1)
    p = div n f
    n' = mod n f
    (ys, zs) = splitAt p xs

factorial :: (Eq t, Num t) => t -> t -> t
factorial acc 0 = acc
factorial acc n = factorial (acc * n) (n - 1)
