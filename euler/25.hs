{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

main :: IO ()
main = print . length . takeWhile ((>) 1000 . countDigit) $ fibos 0 1

fibos :: Integer -> Integer -> [Integer]
fibos a b = a : fibos b (a + b)

countDigit :: Integer -> Int
countDigit n
    | n < 10 = 1
    | otherwise = 1 + countDigit (div n 10)
