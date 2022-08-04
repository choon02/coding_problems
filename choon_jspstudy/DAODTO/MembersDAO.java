package com.jsp.members;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Timestamp;
import java.util.ArrayList;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.sql.DataSource;

public class MembersDAO {
	//싱글톤 패턴으로
	//생성자에서 DataSource 객체 얻어 필드 초기화
	private DataSource ds;
	private Connection conn;
	private PreparedStatement pstmt;
	private ResultSet rs;
	
	private MembersDAO() {
		try {
			Context context = new InitialContext();
			ds = (DataSource) context.lookup("java:comp/env/jdbc/oracle");
		}catch(Exception e) {
			e.printStackTrace();
		}
		
	}
	private static MembersDAO instance = new MembersDAO();
	
	public static MembersDAO getInstance() {
		return instance;
	}
	
	private void close(Connection conn) {
		try {
			if(conn != null) {
				conn.close();
			}
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	private void close(PreparedStatement pstmt) {
		try {
			if(pstmt != null) {
				pstmt.close();
			}
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	private void close(ResultSet rs) {
		try {
			if(rs != null) {
				rs.close();
			}
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	// 회원가입 후 데이터를 DB에 넣는 메소드
	public int insertMember(MembersDTO dto) {
		int result = 0;
		String query = "insert into members values(?, ?, ?, ?, ?, ?)";
		try {
		    conn = ds.getConnection();
		    pstmt = conn.prepareStatement(query);
		    pstmt.setString(1, dto.getId());
			pstmt.setString(2, dto.getPw());
			pstmt.setString(3, dto.getName());
			pstmt.setString(4, dto.getEmail());
			pstmt.setTimestamp(5, dto.getRegDate());
			pstmt.setString(6, dto.getAddress());
			
			result = pstmt.executeUpdate();
		}catch(Exception e){
			e.printStackTrace();
		}finally {
			close(pstmt);
			close(conn);
		}
		return result;
	}
	// members 테이블에 같은 아이디가 있는지 확인하는 메소드
	public int confirmId(String id) {
		int result = 0;
		String query = "select id from members where id = ?";
		try {
			
			// 같은 아이디가 있다면 멤버가 존재할 때 result값을 1로 지정
			// 같은 아이디가 없다면 멤버가 존재하지 않는다면 result값을 0으로 지정
			conn = ds.getConnection();
			pstmt = conn.prepareStatement(query);
			pstmt.setString(1, id);
			
			rs = pstmt.executeQuery();
			if(rs.next())
			{
				result = 1;
				//멤버가 존재할 때
			}else {
				result = 0;
				//멤버가 존재하지 않을 때
			}
		}catch(Exception e) {
			e.printStackTrace();
		}finally {
			close(rs);
			close(pstmt);
			close(conn);
		}
		return result;
	}
	// id와 pw의 데이터를 받아서 DB에 연결 후 id로 pw 데이터 얻어와 (id, pw) 확인하는 메소드
	// ID => x ID -> o ==> pw o pw x
	// 아이디가 존재하지 않는다면 -1 존재하고 비밀번호가 맞는 경우 1, 비밀번호가 틀린경우 0을 리턴
	public int userCheck(String id, String pw) {
		int result = 0;
		String query="select pw from members where id=?";
		try {
			conn = ds.getConnection();
			pstmt = conn.prepareStatement(query);
			
			pstmt.setString(1, id);
			rs = pstmt.executeQuery();
			if(rs.next())
			{
				String dbPw = rs.getString("pw");
				if(dbPw.equals(pw))
					result = 1;//아이디, 비밀번호 맞는 경우 로그인 OK
				else
					result = 0;//아이디, 비밀번호 틀린 경우 로그인 X
			}
			else {
				result = -1;
			}
		}catch(Exception e)
		{
			e.printStackTrace();
		}finally {
			close(rs);
			close(pstmt);
			close(conn);
		}
		return result;
	}
	//DB에서 id로 해당하는 모든 컬럼의 값을 얻은 후 DTO 객체에 담고 DTO 객체 반환하기
	public MembersDTO getMember(String id) {
		MembersDTO dto = null;
		String query = "select* from members where id=?";
		try {
			conn = ds.getConnection();
			pstmt = conn.prepareStatement(query);
			pstmt.setString(1, id);
			rs = pstmt.executeQuery();
			
			if(rs.next()) {
				String dbId = rs.getString("id");
				String pw = rs.getString("pw");
				String name = rs.getString("name");
				String email = rs.getString("email");
				Timestamp regDate = rs.getTimestamp("regDate");
				String address = rs.getString("address");
				dto = new MembersDTO(dbId, pw, name, email, regDate, address);
			}
		}catch(Exception e) {
			e.printStackTrace();
		}finally {
			close(rs);
			close(pstmt);
			close(conn);
		}
		
		return dto;
	}
	// 회원의 정보를 수정해주는 메소드
	// id 수정 불가 비밀번호 o 이름 x email o regDate x 주소 o
	public int updateMember(MembersDTO dto)
	{
		int result = 0;
		String query = "update members set pw = ?, email = ?, address = ?" + "where id = ?";
		try {
			conn = ds.getConnection();
			pstmt = conn.prepareStatement(query);
			pstmt.setString(1,  dto.getPw());
			pstmt.setString(2, dto.getEmail());
			pstmt.setString(3, dto.getAddress());
			pstmt.setString(4, dto.getId());
			result = pstmt.executeUpdate();
		}catch(Exception e)
		{
			e.printStackTrace();
		}finally {
			close(pstmt);
			close(conn);
		}
		return result;
	}
	//id를 받아 해당하는 멤버 삭제
	public int deleteMember(String id) {
		int result = 0;
		String query = "delete from members where id=?";
		try {
			conn = ds.getConnection();
			pstmt = conn.prepareStatement(query);
			pstmt.setString(1,  id);
			result = pstmt.executeUpdate();
		}catch(Exception e) {
			e.printStackTrace();
		}finally {
			close(pstmt);
			close(conn);
		}
		return result;
	}
}
