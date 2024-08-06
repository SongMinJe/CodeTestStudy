using System;

namespace Programmers_ManyGifts
{
    internal class Program
    {
        public int solution(string[] friends, string[] gifts)
        {
            int answer = 0;
            int indexGive, indexTake = 0;
            int n = friends.Length;
            //주고받는 카운트보드
            int[,] giftExchangeMatrix = new int[n, n];
            //받을거라 예상되는 선물갯수
            int[] predictedGiftsReceived = new int[n];
            //주는 선물 지수
            int[] giftGivingScore = new int[n];

            //주고받는 카운트보드 입력
            for (int i = 0; i < gifts.Length; i++)
            {
                string[] name = gifts[i].Split(' ');
                indexGive = Array.IndexOf(friends, name[0]);
                indexTake = Array.IndexOf(friends, name[1]);
                giftExchangeMatrix[indexGive, indexTake]++;
                giftGivingScore[indexGive]++;
                giftGivingScore[indexTake]--;
            }

            //만들어진 카운트보드를 기반으로 선물지수 분석
            for (int i = 0; i < friends.Length; i++)
            {
                for (int j = i + 1; j < friends.Length; j++)
                {
                    //준 선물의 수 비교
                    //i가 준 선물이 더 많을 경우
                    if (giftExchangeMatrix[i, j] > giftExchangeMatrix[j, i])
                    {
                        predictedGiftsReceived[i]++;
                    }
                    //j가 준 선물이 더 많을 경우
                    else if (giftExchangeMatrix[i, j] < giftExchangeMatrix[j, i])
                    {
                        predictedGiftsReceived[j]++;
                    }
                    //서로 준 선물 갯수가 같은 경우
                    else
                    {
                        //선물 지수 비교
                        //i의 선물 지수가 더 높은 경우
                        if (giftGivingScore[i] > giftGivingScore[j])
                        {
                            predictedGiftsReceived[i]++;
                        }
                        //j의 선물 지수가 더 높은 경우
                        if (giftGivingScore[i] < giftGivingScore[j])
                        {
                            predictedGiftsReceived[j]++;
                        }
                    }
                }
            }
            //제일 큰 값을 선출하기 위한 정렬
            Array.Sort(predictedGiftsReceived);
            //받은 선물 갯수 중 제일 큰 값
            return answer = predictedGiftsReceived[friends.Length - 1];
        }
    }
}