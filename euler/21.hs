{-# OPTIONS_GHC -Wall -Wextra -Wall #-}

main :: IO ()
main = print . sum . filter isAmicable $ [1 .. 9999]

isAmicable :: Int -> Bool
isAmicable 1 = False
isAmicable n = (n /= x) && n == sumDivisor x
  where
    x = sumDivisor n

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
