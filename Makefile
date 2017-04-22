st.exe: st.c
	gcc -Wall st.c -o st.exe -lalleg
clean:
	del st.exe