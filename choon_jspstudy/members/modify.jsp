<%@page import="com.jsp.members.MembersDTO"%>
<%@page import="com.jsp.members.MembersDAO"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	
	<%
		String id = (String)session.getAttribute("id");
		MembersDAO dao = MembersDAO.getInstance();
		MembersDTO dto = dao.getMember(id);
	%>
	<form name="modifyForm" action="modifyCheck.jsp" method="post">
		<input type="hidden" name="id" value="<%=id %>">
		아이디: <%=dto.getId() %><br>
		비밀번호: <input type="password" name="pw" size="10"><br>
		비밀번호 확인: <input type="password" name="pwCheck" size="10"><br>
		
		이름: <%=dto.getName() %><br>
		이메일: <input type="text" name="email" size="20" value="<%=dto.getEmail() %>"><br>
		주소: <input type="text" name="address" size="20" value="<%=dto.getAddress() %>"><br>
		
		<input type="button" value="수정" onclick="modifyFormCheck()">
		&nbsp;&nbsp;&nbsp;&nbsp;
		<input type="button" value="취소" onclick="javascript:window.location='main.jsp'">
	</form>
	<script>
	// 비밀번호와 비밀번호 확인 일치, 비밀번호는 필수
	function modifyFormCheck(){
		var pw = document.modifyForm.pw.value;
		var pwCheck = document.modifyForm.pwCheck.value;
		if(pw == "" || pw == null){
			alert('비밀번호는 필수사항입니다.');
			document.modifyForm.pw.focus();
			return;
		}
		if(pw != pwCheck)
		{
			alert('비밀번호가 일치하지 않습니다.');
			document.modifyForm.pw.focus();
			return;
		}
		document.modifyForm.submit();
	}
	</script>
	
</body>
</html>