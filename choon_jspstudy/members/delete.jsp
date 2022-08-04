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
		int result = dao.deleteMember(id);
		
		if(result == 1){
	%>
		<script>
			alert('회원 탈퇴가 정상적으로 되었습니다.');
			window.location = 'logout.jsp';
		</script>
	<%
		}else{
	%>
		<script>
			alert('회원 탈퇴를 실패했습니다.');
			history.back();
		</script>
	<%
		}	
	%>
</body>
</html>