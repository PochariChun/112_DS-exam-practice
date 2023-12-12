# include <stdio.h>
# include <stdlib.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    char** graph = (char **)malloc(m * sizeof(char *));
    for (int i=0; i<m; i++)
         graph[i] = (char *)malloc(n * sizeof(char));
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            scanf(" %c", &graph[i][j]);
        }

    }
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (graph[i][j] == '0') {
                graph[i][j] = '_';
            }
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (i==0 || i==m-1 || j==0 || j==n-1) {
                if (graph[i][j] == '1') {
                    graph[i][j] = '0';
                } 
            } else {
                if (graph[i][j] == '1') {
                    if (graph[i][j+1] == '_' || graph[i][j-1] == '_' || graph[i+1][j] == '_' || graph[i-1][j] == '_') {
                        graph[i][j] = '0';
                    }
                }
            }
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (graph[i][j] == '1') {
                graph[i][j] = '_';
            }
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (j==n-1) {
                printf("%c", graph[i][j]);
            } else {
                printf("%c ", graph[i][j]);
            }
        }
        printf("\n");
    }

    for (int i=0; i<m; i++)
         free(graph[i]);
    free(graph);

    return 0;
}