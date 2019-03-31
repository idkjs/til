fn main(){
    // ミュータブルな変数束縛
    let mut x = 5;
    println!("{}", x);
    // 以下はxの値を変更したのではなく束縛先を変えただけ
    x = 6;
    println!("{}", x);

    // ミュータブル参照へのイミュータブルな束縛
    let y = &mut x;
    println!("{}", y);
    // yの束縛先を変えることは出来ないが束縛されているものを変化させることは可能
    *y = 13;
    println!("{}", y);
}

