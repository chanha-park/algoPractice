{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

main :: IO ()
main = print . maximum . map (\x -> (countCase x, x)) $ [1 .. (1000 :: Int)]

countCase :: Integral c => c -> Int
countCase n
    | odd n = 0
    | otherwise =
        length
            [ (a, b, c)
            | a <- [1 .. (div n 3)]
            , b <- [a + 1 .. (div n 2)]
            , let c = n - a - b
            , a * a + b * b == c * c
            ]
