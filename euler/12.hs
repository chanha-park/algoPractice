{-# OPTIONS_GHC -Wall -Wextra -Wall #-}

main :: IO ()
main = print . head . filter ((> 500) . countDivisor) . map triNum $ [1 ..]

triNum :: Integer -> Integer
triNum n = div (n * (n + 1)) 2

countDivisor :: Integer -> Integer
countDivisor n = foldr fn 1 (factorize n)
  where
    fn (_, b) c = (b + 1) * c

factorize :: Integer -> [(Integer, Integer)]
factorize n = factor' n 2 []
  where
    factor' :: Integer -> Integer -> [(Integer, Integer)] -> [(Integer, Integer)]
    factor' 1 _ xs = xs
    factor' m p xs
        | p * p > m = (m, 1) : xs
        | mod m p == 0 = factor' m' (p + 1) ((p, x) : xs)
        | otherwise = factor' m (p + 1) xs
      where
        (m', x) = countOrder m p 0
        countOrder :: Integer -> Integer -> Integer -> (Integer, Integer)
        countOrder a b acc
            | mod a b == 0 = countOrder (div a b) b (acc + 1)
            | otherwise = (a, acc)
