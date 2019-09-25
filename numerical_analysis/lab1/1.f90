program solve1
  implicit none
  integer :: n
  Read*, n
  if (is_palindrome(n)) then
    print '(A)', 'true'
  else
    print '(A)', 'false'
  end if

  contains
  logical function is_palindrome(i)
    integer :: arr(100), last = -1, i
    logical :: ok = .true.
    do while (i > 0)
      arr(last + 1) = mod(i, 10)
      i = i / 10
      last = last + 1
    end do
    do i = 0, last / 2
      ok = ok .and. (arr(i) .eq. arr(last - i))
    end do
    is_palindrome = ok
  end function is_palindrome

end program solve1