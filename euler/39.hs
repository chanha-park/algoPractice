{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

import Data.List

main :: IO ()
main =
    print
        . maximum
        . map (\x -> (length . findCase $ x, x))
        . enumFromTo 1
        . (`quot` 2)
        $ (1000 :: Int)

findCase :: Integral a => a -> [[a]]
findCase p
    | odd p = []
    | otherwise =
        map head . group . sort $
            [ if a < b then [a, b, c] else [b, a, c]
            | k <- divisors p
            , let p' = div p k
            , m <- divisors p'
            , m * m < p'
            , 2 * m * m > p'
            , let n = div p' m - m
            , let a = k * (m * m - n * n)
            , let b = k * (2 * m * n)
            , let c = p - a - b
            ]

divisors :: Integral b => b -> [b]
divisors n = filter ((== 0) . rem n) [1 .. n] -- can be improved
