#include <cstdio>
using namespace std;

int main()
{
  printf("\033[2J");   /* 画面をクリア */
  printf("\033[5;10H"); /* カーソルを移動 */
  printf("\033[33m");   /* 文字色を黄色に */
  printf("Hello!\n");  /* メッセージを出力 */

  printf("Press [Enter]...\n");  /* メッセージを出力 */
  getchar();     /* キー入力を待つ */
  printf("\033[93m");   /* 文字色を標準に */
  return 0;
}