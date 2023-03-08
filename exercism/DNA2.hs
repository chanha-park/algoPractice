{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

module DNA (nucleotideCounts, Nucleotide (..)) where

import Data.Functor ((<&>))
import Data.List (group, sort)
import Data.Map (Map, fromList)

data Nucleotide = A | C | G | T
    deriving (Eq, Ord, Show)

nucleotideCounts :: String -> Either String (Map Nucleotide Int)
nucleotideCounts xs = stringToArray xs <&> fromList . map fn . group . sort
  where
    fn x = (head x, length x)

stringToArray :: String -> Either String [Nucleotide]
stringToArray [] = Right []
stringToArray ('A' : xs) = (:) <$> Right A <*> stringToArray xs
stringToArray ('C' : xs) = (:) <$> Right C <*> stringToArray xs
stringToArray ('G' : xs) = (:) <$> Right G <*> stringToArray xs
stringToArray ('T' : xs) = (:) <$> Right T <*> stringToArray xs
stringToArray _ = Left "error"
