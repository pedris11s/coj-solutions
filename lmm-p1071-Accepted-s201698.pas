{by ARPO}
type Bignum = record
                d : array[0..101] of Integer;
                l : Byte;
              end;{record}

var
  fe  : Text;
  s   : string;
  i,l,llevo : Byte;
  a,b : Bignum;

procedure Multiplica;
  var llevo,m : Byte; i : Integer;
  begin
    llevo:=0;
    for i:=0 to a.l-1 do begin
       m:=a.d[i]*2+llevo;
       llevo:=m div 10;
       m:=m mod 10;
       b.d[i]:=m;
    end;{for i}
    b.l:=a.l;
    if llevo > 0 then begin
      b.d[b.l]:=llevo;
      Inc(b.l);
    end;{if}
end;{Multiplica}

begin
   assign(fe,''); reset(fe);
   while not eoln(fe) do begin
      readln(fe,s);
      if s = '1' then writeln(1)else begin
       l:=length(s);
       for i:=l downto 1 do a.d[l-i]:=ord(s[i])-48;
       a.l:=l;

       Multiplica;

       llevo:=2;
       i:=0;
       repeat
          if b.d[i] < llevo then begin
             b.d[i]:=10+b.d[i]-llevo;
             llevo:=1;
          end else begin
            b.d[i]:=b.d[i]-llevo;
            llevo:=0;
          end;{else}
          inc(i);
       until (i = b.l) or (llevo = 0);
       if (b.d[b.l-1]=0) and (b.l > 1)then dec(b.l);

       for i:=b.l-1 downto 0 do Write(b.d[i]);
       writeln;
      end;{else}
   end;{while}
   close(fe);
end.