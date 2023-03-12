{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

module Anagram (anagramsFor) where

import Data.Char
import Data.List

anagramsFor :: String -> [String] -> [String]
anagramsFor = filter . isAnagramOf
  where
    isAnagramOf xs ys = (as /= bs) && (sort as == sort bs)
      where
        as = map toLower xs
        bs = map toLower ys
