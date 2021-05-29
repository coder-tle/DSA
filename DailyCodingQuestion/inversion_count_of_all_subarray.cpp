
int main()
{
    memset(bit,0,sizeof(bit));

    long long n;
    sfl(n)

    util arr[n+1];

    f(i,1,n+1)
    {
        sfl(arr[i].val)
        arr[i].idx=i;
    }

    sort(arr+1,arr+n+1,cmp);

    ll ans=0;

    f(i,1,n+1)
    {
        ll temp1=totsum(arr[i].idx);
        ans=(ans+(temp1*(n-arr[i].idx+1))%mod)%mod;
        update(arr[i].idx,arr[i].idx,n);
    }

    pfl(ans)
}
