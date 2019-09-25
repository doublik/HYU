program boj1259
  implicit none
  integer :: n
  do
    read*, n
    if (n .eq. 0) then
      exit
    end if
    if (is_palindrome(n)) then
      print '(A)', 'yes'
    else
      print '(A)', 'no'
    end if
  end do

  contains
  logical function is_palindrome(i)
    integer :: arr(100), last, i
    logical :: ok
    last = -1
    ok = .true.
    do while (i > 0)
      arr(last + 1) = mod(i, 10)
      i = i / 10
      last = last + 1
    end do
    do i = 0, last / 2
      ok = ok .and. (arr(i) == arr(last - i))
    end do
    is_palindrome = ok
  end function is_palindrome
end program boj1259