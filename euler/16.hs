{-# OPTIONS_GHC -Wall -Wextra -Wall #-}

main :: IO ()
main = print . sumDigit 0 . twoPower 1 $ 1000

twoPower :: Integer -> Int -> Integer
twoPower acc 0 = acc
twoPower acc x = twoPower (2 * acc) (x - 1)

sumDigit :: Integer -> Integer -> Integer
sumDigit acc x
    | x < 10 = acc + x
    | otherwise = sumDigit (acc + mod x 10) (div x 10)
