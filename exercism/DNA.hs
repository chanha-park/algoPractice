{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

module DNA (toRNA) where

toRNA :: String -> Either Char String
toRNA [] = Right []
toRNA (x : xs)
    | x == 'G' = (:) <$> Right 'C' <*> toRNA xs
    | x == 'C' = (:) <$> Right 'G' <*> toRNA xs
    | x == 'T' = (:) <$> Right 'A' <*> toRNA xs
    | x == 'A' = (:) <$> Right 'U' <*> toRNA xs
    | otherwise = Left x
