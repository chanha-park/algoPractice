{-# OPTIONS_GHC -Wall -Wextra -Wall #-}

main :: IO ()
main = print . sumDigit 0 . facto 1 $ (1000 :: Integer)

facto :: (Eq t, Num t) => t -> t -> t
facto acc 0 = acc
facto acc n = facto (acc * n) (n - 1)

sumDigit :: Integral t => t -> t -> t
sumDigit acc n
    | n < 10 = acc + n
    | otherwise = sumDigit (acc + mod n 10) (div n 10)
