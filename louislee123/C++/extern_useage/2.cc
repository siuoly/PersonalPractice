// global variable set
/*
 * 預在使用其他object file的global變數
 * 需要在自身object file 先宣告
 * 
 * ex:
 * // main.cc
 * int i;
 *
 * // global.cc
 * int i =10;
 * 
 * --> error: 重複定義變數.....
 * 因為一般宣告和定義會在同一句statement中
 * 然而main.cc不宣告又無法使用 變數i
 * 故需要僅宣告而不定義:
 * 
 * ex:
 * // main.cc
 * extern int i;
 *
 * // global.cc
 * int i=10;
 * 如此main.cc可以正常使用global.cc的變數
 * i.
 */
int i = 1000;
