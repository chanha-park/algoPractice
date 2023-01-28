{-# OPTIONS_GHC -Wall -Wextra -Wall #-}

main :: IO ()
main = print . rangeLCM $ 20

-- main = print . foldr lcm 1 $ ([1..20] :: [Int])

rangeLCM :: Int -> Int
rangeLCM n = evalFactor . map (countOrder n) . primesLE $ n

evalFactor :: [(Int, Int)] -> Int
evalFactor = foldr fn 1
    where
        fn :: (Int, Int) -> Int -> Int
        fn = (*) . (($) (uncurry (^)))

countOrder :: Int -> Int -> (Int, Int)
countOrder n p
    | p > n = (p, 0)
    | otherwise = (p, (+ 1) . snd . countOrder (div n p) $ p)

primesLE :: Int -> [Int]
primesLE n = sieve [2..n]

sieve :: [Int] -> [Int]
sieve [] = []
sieve (p : ps) = p : sieve [x | x <- ps, mod x p /= 0]
