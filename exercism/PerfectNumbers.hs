{-# OPTIONS_GHC -Wall -Wextra #-}

module PerfectNumbers (classify, Classification (..)) where

data Classification = Deficient | Perfect | Abundant deriving (Eq, Show)

classify :: Int -> Maybe Classification
classify n
    | n <= 0 = Nothing
    | s < n = Just Deficient
    | s > n = Just Abundant
    | otherwise = Just Perfect
  where
    s = aliquotSum n

aliquotSum :: Int -> Int
aliquotSum n = sum . filter (\x -> mod n x == 0) $ [1 .. n - 1]
