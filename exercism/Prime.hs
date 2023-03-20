{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

module Prime (nth) where

nth :: Int -> Maybe Integer
nth n
    | n < 1 = Nothing
    | otherwise = Just (primes [2 ..] !! (n - 1))

primes :: Integral a => [a] -> [a]
primes [] = []
primes (x : xs) = x : primes [y | y <- xs, mod y x /= 0]
