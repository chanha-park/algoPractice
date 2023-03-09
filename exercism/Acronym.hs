{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

module Acronym (abbreviate) where

import Data.Char
import Data.List

abbreviate :: String -> String
abbreviate = concatMap fn . words

fn :: String -> String
fn x
    | all isLower x = [toUpper . head $ x]
    | all isUpper x = [head x]
    | any isAlpha x =
        concatMap
            ( \a ->
                if all isLower a
                    then [toUpper . head $ a]
                    else
                        if all isUpper a
                            then [head a]
                            else filter isUpper a
            )
            . filter (any isAlpha)
            . groupBy (\a b -> isAlpha a == isAlpha b)
            . filter (/= '\'')
            $ x
    | otherwise = []
