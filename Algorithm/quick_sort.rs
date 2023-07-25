///const LEN: usize = 10;
//const LEN: usize = 2;
const LEN: usize = 1;

fn main() {
    //let mut a: [usize; LEN] = [0, 9, 8, 7, 6, 5, 4, 3, 2, 1];
    //let mut a: [usize; LEN] = [0, 9];
    let mut a: [usize; LEN] = [0];
    quick_sort(&mut a, 0, LEN-1);
    for i in a {
        println!("{i}");
    }
}

fn partition(a: &mut [usize; LEN], l: usize, r:usize) -> usize {
    let mid: usize = a[r];
    let mut i: usize = l; // i <= j
    let mut j: usize = l;
    while j < r {
        //j迭代器
        //i小于等于mid
        if a[j] <= mid
        {
            let tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i += 1;
        }
        j += 1;
    }
    //迭代完，i指向值左边第一个大于mid的值或者为r；所以将其与中间值交换
    a[r] = a[i];
    a[i] = mid;
    i
    
}

fn quick_sort(a: &mut [usize; LEN], l: usize, r: usize) {
    println!("quick sort.");

    if r <= l {
        return;
    }
    let p = partition(a, l, r);
    let nl = p - 1;
    let nr = p + 1;
    quick_sort(a, l, nl);
    quick_sort(a, nr, r);
}
