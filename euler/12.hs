{-# OPTIONS_GHC -Wall -Wextra -Wall #-}

main :: IO ()
main = print . head . filter ((> 500) . countDivisor) . map triNum $ [1 ..]

triNum :: Int -> Int
triNum n = div (n * (n + 1)) 2

countDivisor :: Int -> Int
countDivisor n = foldr fn 1 (factorize n)
  where
    fn (_, b) c = (b + 1) * c

factorize :: Int -> [(Int, Int)]
factorize n = factor' n 2 []
  where
    factor' :: Int -> Int -> [(Int, Int)] -> [(Int, Int)]
    factor' 1 _ xs = xs
    factor' m p xs
        | mod m p == 0 = factor' m' (p + 1) ((p, x) : xs)
        | otherwise = factor' m (p + 1) xs
      where
        (m', x) = countOrder m p 0
        countOrder :: Int -> Int -> Int -> (Int, Int)
        countOrder a b acc
            | mod a b == 0 = countOrder (div a b) b (acc + 1)
            | otherwise = (a, acc)
