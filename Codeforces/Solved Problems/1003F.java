import java.io.*;
import java.util.*;
class CF
{
	public static void main(String [] args)throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		String M = br.readLine();
		int length = M.length();
		String words[] = M.split(" ");
		int len[] = new int[N];
		int cum[][] = new int[N][N];
		int dp[][] = new int[N][N];
		int DP[][] = new int[N][N];
		for(int i = 0; i<N; i++)
		{
			for(int j=0; j<N; j++)
				DP[i][j] = -1;
		}
		for(int i=0; i<N; i++)
			len[i] = words[i].length();
		for(int i=0; i<N; i++)
		{
			cum[i][i] = len[i];
			for(int j = i + 1; j < N; j++)
				cum[i][j] = cum[i][j - 1] + len[j];
		}
		for(int i=0; i<N; i++)
		{
			for(int j = 0; j< N; j++)
				if(words[i].equals(words[j]))dp[i][j] = 1;
		}
		int ret = length;
		for(int i = N - 1; i >=0; i--)
		{
			for(int j = i + 1; j < N; j++)
			{
				//i and j are my starting points
				if(dp[i][j]==0)continue;
				int cnt1 = i; int cnt2 = j;
				while((cnt2 < N) && (cnt1 < j) && (dp[cnt1][cnt2] == 1))
				{
					
					int tmp = length - cum[i][cnt1] + (cnt1 - i + 1) - cum[j][cnt2] + (cnt2 - j + 1) - 2*(cnt2 - j);
					ret = Math.min(ret, tmp);
					if(DP[j][cnt2] == -1)
					{
						if(DP[i][cnt1] != -1)
							DP[i][cnt1] = Math.min(DP[i][cnt1] ,tmp);
						else
							DP[i][cnt1] = tmp;
					}
					else
					{
						//System.out.println(i + " " + cnt1 + " " + j + " " + cnt2);
						if(DP[i][cnt1] != -1)
							DP[i][cnt1] = Math.min(DP[i][cnt1], DP[j][cnt2] - cum[i][cnt1] + (cnt1 - i + 1) - (cnt2 - j));
						else
							DP[i][cnt1] = DP[j][cnt2] - cum[i][cnt1] + (cnt1 - i + 1) - (cnt2 - j);
						//System.out.println(DP[0][1	]);
					}
					cnt1++;
					cnt2++;
				}
				
			}
		}
		for(int i=0; i<N; i++)
		{
			for(int j = 0; j < N; j++)
				if(DP[i][j] != -1)
					ret = Math.min(ret, DP[i][j]);
		}
		System.out.println(ret);
	}
}	