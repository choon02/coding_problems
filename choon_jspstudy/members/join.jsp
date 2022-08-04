<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>

	<%--
		회원가입 폼 만들기(아이디, 비밀번호, 비밀번호 확인, 이름, 이메일, 주소)
		자바스크립트 함수로 유효성 체크하기
		자바스크립트에서 유효성 검사가 끝나면 joinCeck.jsp로 전송하기
	 --%>
	 <h2>회원가입</h2>
	 <form name="joinForm" action="joinCheck.jsp" method="post">
		아이디: <input type="text" name="id" size="10"><br>
		비밀번호: <input type="password" name="pw" size="20"><br>
		비밀번호 확인: <input type="password" name="pwCheck" size="20"><br>
		이름: <input type="text" name="name" size="10"><br>
		이메일: <input type="text" name="email" size="20"><br>
		주소: <input type="text" name="address" size="20"><br>			
	    <input type="button" value="회원가입" onclick="joinFormCheck()">
	    
	</form>
	<script>
		function joinFormCheck(){
			
			var id = document.joinForm.id.value;
			var pw = document.joinForm.pw.value;
			var pwCheck = document.joinForm.pwCheck.value;
			var name = document.joinForm.name.value;
			
			if(id == "" || id == null){
				alert('아이디는 필수사항입니다.');
				document.joinForm.id.focus();
				return;
			}
			if(id.length < 4){
				alert('id는 4글자 이상이어야 합니다.');
				document.joinForm.id.focus();
				return;
			}
			if(pw == "" || pw == null){
				alert('비밀번호는 필수사항입니다.');
				document.joinForm.pw.focus();
				return;
			}
			if(pw != pwCheck){
				alert('비밀번호가 일치하지 않습니다');
				doucument.joinForm.pw.focus();
			}
			if(name == "" || name == null){
				alert('이름은 필수사항입니다.');
				document.joinForm.name.focus();
				return;
			}
			document.joinForm.submit();
		}
	</script>
</body>
</html>