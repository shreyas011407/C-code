#include <stdio.h>

char str[100], pat[50], rep[50], ans[100];
int i, j, m, k, c, flag = 0;

void stringmatch()
{
    i = m = c = j = 0;
    while (str[c] != '\0')
    {
        if (str[m] == pat[i])
        {
            i++;
            m++;
            if (pat[i] == '\0')          /* full pattern matched */
            {
                flag = 1;
                for (k = 0; rep[k] != '\0'; k++, j++)
                    ans[j] = rep[k];     /* copy replacement string */
                i = 0;
                c = m;                   /* continue after the match */
            }
        }
        else                             /* mismatch */
        {
            ans[j] = str[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }
    ans[j] = '\0';
}

int main()
{
    printf("\n Enter the main string: \n");
    scanf(" %[^\n]", str);
    printf("\n Enter the pattern string: \n");
    scanf(" %[^\n]", pat);
    printf("\n Enter the replace string: \n");
    scanf(" %[^\n]", rep);
    stringmatch();

    if (flag == 1)
        printf("The resultant string is \n %s", ans);
    else
        printf("\n Pattern string not found:");

    return 0;
}