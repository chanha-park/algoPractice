{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

main :: IO ()
main = print $ maxFactor 600851475143 2

-- min factor s.t. >= p
minFactor :: Integer -> Integer -> Integer
minFactor n p
    | p * p > n = n
    | mod n p == 0 = p
    | otherwise = minFactor n (p + 1)

-- max factor s.t. >= p
maxFactor :: Integer -> Integer -> Integer
maxFactor n p
    | k == n = n
    | k == p = maxFactor (div n p) p
    | otherwise = maxFactor n (p + 1)
  where
    k = minFactor n p
