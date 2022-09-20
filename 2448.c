/*

                       *                        
                      * *                       
                     *****                      
                    *     *                     
                   * *   * *                    
                  ***** *****                   
                 *           *                  
                * *         * *                 
               *****       *****                
              *     *     *     *               
             * *   * *   * *   * *              
            ***** ***** ***** *****             
           *                       *            
          * *                     * *           
         *****                   *****          
        *     *                 *     *         
       * *   * *               * *   * *        
      ***** *****             ***** *****       
     *           *           *           *      
    * *         * *         * *         * *     
   *****       *****       *****       *****    
  *     *     *     *     *     *     *     *   
 * *   * *   * *   * *   * *   * *   * *   * *  
***** ***** ***** ***** ***** ***** ***** *****

*/

#include <stdio.h>
#include <stdlib.h>

char	c = '*';

void	fill_map(char **map, int x, int y, int size)
{
	if (size == 3)
	{
		map[x][y + 2] = c;
		map[x + 1][y + 1] = c;
		map[x + 1][y + 3] = c;
		map[x + 2][y + 0] = c;
		map[x + 2][y + 1] = c;
		map[x + 2][y + 2] = c;
		map[x + 2][y + 3] = c;
		map[x + 2][y + 4] = c;
	}
	else
	{
		size >>= 1;
		fill_map(map, x, y + size, size);
		fill_map(map, x + size, y, size);
		fill_map(map, x + size, y + size * 2, size);
	}
}

int	main(void)
{
	int	n;
	char	**map;

	scanf("%d", &n);
	map = malloc(sizeof(char *) * (n + 1));
	for (int i = 0; i < n; i++)
	{
		map[i] = malloc(sizeof(char) * (n << 1));
		for (int j = 0; j < 2 * n - 1; j++)
			map[i][j] = ' ';
	}
	fill_map(map, 0, 0, n);
	for (int i = 0; i < n; i++)
		printf("%s\n", map[i]);
	return (0);
}
