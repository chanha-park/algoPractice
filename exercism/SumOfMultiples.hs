module SumOfMultiples (sumOfMultiples) where

sumOfMultiples :: [Integer] -> Integer -> Integer
sumOfMultiples factors limit =
    sum
        . filter (\x -> any ((== 0) . mod x) (filter (/= 0) factors))
        . takeWhile (< limit)
        $ [1 ..]
